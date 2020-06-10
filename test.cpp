/* 14.2 상속을 이용한 프로그래밍
        10장의 부분적으로 재워진 배열 상속
        동적 변수를 포함한 클래스의 상속
        - 파생 클래스의 복사 생성자: 기반 클래스의 복사 생성자 호출
        - 파생 클래스의 할당 연산자: 기반 클래스의 할당 연산자 호출
        - 파생 클래스의 소멸자: 기반 클래스의 소멸자 자동 호출
*/
#include <iostream> 
using namespace std;

//--- 기본 클래스 DArray 인터페이스 
class DArray {
public:
    DArray();   // 용량=50
    DArray(int size);
    DArray(const DArray& tg);  // 복사 생성자 

    int getcp() { return cp; }
    int getused() { return used; }
    void addem(double em) { a[used] = em; used++; }
    double getem(int index) { return a[index]; }
    void initial();  // 배열 초기화 
    DArray& operator = (const DArray& rs);  // 할당 연산자 
    ~DArray();

protected: // private 대신 
    double* a;
    int cp;     // 용량
    int used;   // 사용량 
};

//--- 파생클래스 DArrayBack 인터페이스 
class DArrayBack : public DArray // 상속
{
public:
    // 생성자 
    DArrayBack();   // 용량=50
    DArrayBack(int cpb);
    // 복사 생성자 
    DArrayBack(const DArrayBack& object);
    void backup();  // 백업 
    void restore();  // 복구 
    // 할당 연산자
    DArrayBack& operator = (const DArrayBack& rsb);
    // 소멸자
    ~DArrayBack();
private:
    double* b; // 백업 배열 
    int usedB; // 백업 배열의 사용량 
};

//--- 파생클래스 DArrayBack 구현  
DArrayBack::DArrayBack() : DArray(), usedB(0)
{
    b = new double[cp];
}

DArrayBack::DArrayBack(int cpb) : DArray(cpb), usedB(0) {
    b = new double[cp];
}
// 복사 생성자: 기반 클래스의 복사 생성자 호출 
DArrayBack::DArrayBack(const DArrayBack& object) : DArray(object), usedB(0)
{
    b = new double[cp];
    usedB = object.usedB;
    for (int i = 0; i < usedB; i++)
        b[i] = object.b[i];
}

void DArrayBack::backup() {
    usedB = used;
    for (int i = 0; i < usedB; i++)
        b[i] = a[i];
}

void DArrayBack::restore() {
    used = usedB;
    for (int i = 0; i < used; i++)
        a[i] = b[i];
}

// 할당 연산자 오버로딩 
DArrayBack& DArrayBack::operator = (const DArrayBack& rsb)
{
    DArray::operator=(rsb); //기반클래스의 할당연산자 호출
    if (cp != rsb.cp)
    {
        delete[] b;
        b = new double[rsb.cp];
    }
    usedB = rsb.usedB;
    for (int i = 0; i < usedB; i++)
        b[i] = rsb.b[i];
    return *this;
}

// 파생 클래스의 소멸자는 기반 클래스의 소멸자를 자동 호출한다.
// 소멸자 호출 순서는 생성자 호출 순서의 역순
DArrayBack::~DArrayBack()
{
    delete[] b;
}

int main() {

    DArrayBack db1, db2(10);

    // 백업, 복구 
    db1.addem(2); db1.addem(3); db1.addem(4); db1.addem(5);
    db1.backup();   // 백업 
    db1.initial();  // 초기화 
    cout << "db1.a= " << db1.getem(0) << " " << db1.getem(1) << " "
        << db1.getem(2) << " " << db1.getem(3) << endl;
    db1.restore();  // 복구 
    cout << "db1.a= " << db1.getem(0) << " " << db1.getem(1) << " "
        << db1.getem(2) << " " << db1.getem(3) << endl;

    // 복사 생성자 
    DArrayBack db3(db1);
    cout << "db3.a= " << db3.getem(0) << " " << db3.getem(1) << " "
        << db3.getem(2) << " " << db3.getem(3) << endl;

    // 할당 연산자(=)
    db2 = db3;
    cout << "db2.cp=" << db2.getcp() << " db2.used=" << db2.getused() << endl;
    cout << "db2.a= " << db2.getem(0) << " " << db2.getem(1) << " "
        << db2.getem(2) << " " << db2.getem(3) << endl;

    return 0;
}

//--- 기본 클래스 DArray 구현 
DArray::DArray() : cp(50), used(0) {
    a = new double[cp];
}
DArray::DArray(int size) : cp(size), used(0) {
    a = new double[cp];
}
// 복사 생성자 
DArray::DArray(const DArray& tg) : cp(tg.cp), used(tg.used) {
    a = new double[cp];
    for (int i = 0; i < used; i++)
        a[i] = tg.a[i];
}
// 할당연산자(=) 오버로딩 
DArray& DArray::operator = (const DArray& rs) {
    if (this == &rs) {
        return *this;
    }
    else {
        cp = rs.cp;
        used = rs.used;
        delete[] a;   // 기존 동적배열 a를 반환한다. 
        a = new double[cp];
        for (int i = 0; i < used; i++)
            a[i] = rs.a[i];
        return *this;
    }
}
void DArray::initial() {
    for (int i = 0; i < used; i++)
        a[i] = 0.0;
    used = 0;
}
// 소멸자 
DArray::~DArray() {
    delete[] a;
}
