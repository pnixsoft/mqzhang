#include <iostream>
#include <chrono>
using namespace std;

const int MaxSize = 100;

template <typename DataType>
class SeqList
{
public:
    SeqList();
    SeqList(DataType a[], int n);
    ~SeqList();
    int Length();
    int Empty();
    void PrintList();
    DataType Get(int i);
    int Locate(DataType x);
    void Insert(int i, DataType x);
    DataType Delete(int i);
    void Delallx(DataType x);

private:
    DataType data[MaxSize];
    int length;
};

template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
    if(n>MaxSize) throw "非法参数";
    for(int i=0;i<n;i++)
       data[i]=a[i];
    length = n;
    cout<<endl<<"testing construction function: OK."<<endl;
}

template <typename DataType>
SeqList<DataType>::~SeqList()
{
    cout<<"testing unconstruction function: OK."<<endl;
    cout<<"==================== End ========================"<<endl;
}


template <typename DataType>
void SeqList<DataType>::PrintList()
{
    for(int i=0;i<length;i++)
        cout<<data[i]<<"\t";
    cout<<endl;
}

template <typename DataType>
int SeqList<DataType>::Length()
{
    return length;
}

template <typename DataType>
DataType SeqList<DataType>::Get(int i)
{
    if(i<1 || i>length) throw "查找位置非法";
    else return data[i-1];
}


template <typename DataType>
int SeqList<DataType>::Locate(DataType x)
{
    for(int i=0;i<length;i++)
        if (data[i]==x) return i+1;
    return 0;
}


template <typename DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
    if(length == MaxSize) throw "上溢出";
    if (i<1||i>length+1) throw "插入位置错误。";

    
    for(int j=length;j>=i; j--)
        data[j]=data[j-1];
    data[i-1] = x;
    length++;
}

template <typename DataType>
DataType SeqList<DataType>::Delete(int i)
{
    DataType x;
    if (length==0) throw "下溢出";
    if (i<1||i>length) throw "删除位置错误。";
    x = data[i-1];
    for (int j=i;j<length;j++)
        data[j-1]=data[j];
    length--;
    return x;
}


template <typename DataType>
void SeqList<DataType>::Delallx(DataType x)
{
    int i=0,j;
    while(i<length && data[i]!=x)
        i++;
    for(j=i+1;j<length;j++)
    {
        if (data[j]!=x)
            data[i++]=data[j];
    }
    length = i;
}

int main()
{
    auto startTime = std::chrono::high_resolution_clock::now();
    

    int r[5]={1,2,3,2,5},i,x;
    SeqList<int> L(r,5);

    cout<<"====================Start========================"<<endl;

    cout<<endl;
    cout<<"1.当前线性表的数据为："<<endl;
    L.PrintList();
    L.Delallx(2);
    L.PrintList();
    
    // cout<<endl;
    // try
    // {
    //     L.Insert(2,8);
    //     cout<<"2.执行插入操作后数据为："<<endl;
    //     L.PrintList();
    // } catch (char *str) {cout<<str<<endl;}
    // cout<<"当前线性表长度为："<<L.Length()<<endl;
    
    // cout<<endl;
    // cout<<"3. 请输入要查找的数据：";
    // cin>>x;
    // i = L.Locate(x);
    // if (i==0) cout<<"查找失败。"<<endl;
    // else cout<<"元素"<<x<<"的位置为："<<i<<endl;

    // cout<<endl<<"4. 请输入要查找第几个元素值：";
    // cin>>i;
    // cout<<"第 "<<i<<" 个元素值是： "<<L.Get(i)<<endl;

    // cout<<endl<<"5. 请输入要删除第几个元素：";
    // cin>>i;
    // x = L.Delete(i);
    // cout<<"删除的元素为："<<x<<"，删除后线性表中数据为："<<endl;
    // L.PrintList();

    // auto endTime = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::milli> fp_ms = endTime - startTime;

    // std::cout << "Runing time is: "<<fp_ms.count()/1000 <<" s"<< std::endl;
    return 0;
}

// Notes01: 清除由auto引起的C++11 warning：
// https://clay-atlas.com/us/blog/2021/09/18/cpp-en-warning-auto-extension/
// echo 'alias g++="g++ -std=c++11"' >> ~/.bash_profile
// source ~/.bash_profile