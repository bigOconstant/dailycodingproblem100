
#include <iostream>
#include <vector>
using namespace std;
int getSteps(std::vector<std::vector<int>> );

int main()
{
    std::vector<std::vector<int>> testdata1;
    testdata1.push_back({0,0});
    testdata1.push_back({1,1});
    testdata1.push_back({1,2});

    std::vector<std::vector<int>> testdata2;
    testdata2.push_back({2,2});
    testdata2.push_back({2,6});

    std::vector<std::vector<int>> testdata3;
    testdata3.push_back({0,0});
    testdata3.push_back({1,1});
    testdata3.push_back({1,2});
    testdata3.push_back({3,6});


    std::cout<<"test1 steps:"<<getSteps(testdata1)<<endl;
    std::cout<<"test2 steps:"<<getSteps(testdata2)<<endl;
    std::cout<<"tes32 steps:"<<getSteps(testdata3)<<endl;

   return 0;
}

int getSteps(std::vector<std::vector<int>> input){
     auto count = 0;
    if(input.size() <2){
        return 0;
    }

    auto last = input.back();
    input.pop_back();

    auto y = abs(last.back() - input.back().back());
    auto x = abs(last.front() - input.back().front());

    if (x > y){
        count += x;
    }else {
        count += y;
    }
    return count + getSteps(input);
}
