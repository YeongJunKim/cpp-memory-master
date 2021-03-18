#include <iostream>
#include <memory>

class unique_basic
{
private:
    int A;
    int B;
    int C;
    int value;
public:
    unique_basic(int _A, int _B, int _C) : A(_A), B(_B), C(_C) {}
    ~unique_basic(){}
    void setValue(int _val){value = _val;}
    int getValue(){return value;}
    void printA(){std::cout << "A: " << A << std::endl;}
    void printB(){std::cout << "B: " << B << std::endl;}
    void printC(){std::cout << "C: " << C << std::endl;}
};

void f1(std::unique_ptr<unique_basic> _uptr) //값으로 받을때
{
    std::cout << __func__ << std::endl;
    _uptr->printA();
}

void f2(const std::unique_ptr<unique_basic> &_uptr) //참조로 받을때
{
    std::cout << __func__ << std::endl;
    // const로 받으면 "공유" 된다. 따라서 여기서 사용은 불가능하다.
    // _uptr->printB();
}

void f3(std::unique_ptr<unique_basic> &&_uptr) // raw value로 받을때
{
    std::cout << __func__ << std::endl;
}

void f4(std::unique_ptr<unique_basic> &&_uptr) // raw value로 받고 move시킬때
{
    std::unique_ptr<unique_basic> a = std::move(_uptr);
    std::cout << "value: " << a->getValue() << std::endl;
}

int main(void)
{
    std::unique_ptr<unique_basic> ua = std::make_unique<unique_basic>(1,2,3);
    ua->printA();
    unique_basic* pa = nullptr;
    pa = ua.get();
    pa->printB();

    // unique_ptr(const unique_ptr&) = delete;
    // f1(ua);
    // rvalue로 넘겨야 한다.
    f1(std::move(ua));

    // 함수로 ua 자원을 넘겼기 때문에 ua를 여기서는 사용 불가능하다.
    // ua->printB();
    ua = std::make_unique<unique_basic>(3,2,1);

    f2(ua);

    ua->setValue(10);
    std::cout << "value: " << ua->getValue() << std::endl;

    f3(std::move(ua));

    f4(std::move(ua));

    std::cout << "value: " << ua->getValue() << std::endl;
    // std::cout << ua.get() << std::endl;
    // f4(std::move(ua));
}