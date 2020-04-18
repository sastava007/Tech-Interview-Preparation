/*
    https://practice.geeksforgeeks.org/problems/special-stack/1

    This is a functional problem, which need to be solved in O(1) space without using another stack 

*/

int min_ele;

void push(int a)
{
    if(s.empty())
    {
        s.push(a);
        min_ele=a;
    }
    else if(a>=min_ele)
        s.push(a);
    else
    {
        s.push(2*a-min_ele);
        min_ele=a;
    }
}

bool isFull(int n)
{
    return s.size()==n;
}

bool isEmpty()
{
    return s.size()==0;
}

int pop()
{
    if(s.empty())
        return -1;
    else if(s.top()>=min_ele)
    {
        int ele=s.top();
        s.pop();
        return ele;
    }
    else //whenever element in stack is < min_ele this means that there's been some annomaly or corruption in that element becz no element can be less than min_ele, so we need to decode it's original value
    {
        int temp=min_ele;
        min_ele = 2*min_ele - s.top();
        return temp;
    }
}

int getMin()
{
   if(s.empty())
        return -1;
    
    return min_ele;
}