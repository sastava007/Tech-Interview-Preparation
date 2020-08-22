/* Find the total importace of employee with id */

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) 
    {
        unordered_map<int, Employee*> m;
        for(auto emp: employees)
            m[emp->id] = emp;
        
        stack<Employee*> todo;
        todo.push(m[id]);
        
        int importance = 0;
        
        while(!todo.empty())
        {
            auto emp = todo.top();
            todo.pop();;
            
            importance += emp->importance;
            
            for(int e: emp->subordinates)
                todo.push(m[e]);
        }
        return importance;
    }
};