#include <iostream>
#include <memory>


// c++ 포인터er 역할
// std::unique_ptr을 사용하지 않지만, 소유권을 넘길 때
// 함수의 인자로 배열을 넘길 때
// 문자열을 가리킬 때
// 소유권을 넘기지 않고 하나의 객체를 가리킬 때
// ref http://egloos.zum.com/sweeper/v/2826435

class shared_basic
{
private:
    int data;
public:
    shared_basic(int _data): data(_data){}
    ~shared_basic(){}
    void setData(int _data) {data = _data;}
    int getData() {return data;}
};

void f1(std::shared_ptr<shared_basic> _sptr)
{
    // 값에 의한 카운트 증가 4
    std::cout << __func__ << "\t counts: " << _sptr.use_count() << std::endl;
}

int main(void)
{
    std::shared_ptr<shared_basic> sptr1(new shared_basic(10));
    std::cout << "counts: " << sptr1.use_count() << std::endl;
    // 복사 -> 참조 카운트 2
    std::shared_ptr<shared_basic> sptr2(sptr1); 
    std::cout << "counts: " << sptr2.use_count() << std::endl;
    // // 대입 -> 참조 카운트 3
    std::shared_ptr<shared_basic> sptr3 = sptr2; 
    std::cout << "counts: " << sptr2.use_count() << std::endl;
    f1(sptr1);
    // 함수에서 사용후 카운트 감소 3
    std::cout << "counts: " << sptr1.use_count() << std::endl;

    // 카운트 리셋
    sptr3.reset();
    std::cout << "counts: " << sptr1.use_count() << std::endl;
    sptr1.reset();
    std::cout << "counts: " << sptr1.use_count() << std::endl;
}