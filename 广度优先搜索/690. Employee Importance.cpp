/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    Employee* find(vector<Employee*> employees, int id) {
        int leftPtr = 0, rightPtr = employees.size() - 1;
        while (leftPtr <= rightPtr) {
            int middle = (leftPtr + rightPtr) >> 1;

            if (employees[middle]->id < id) {
                leftPtr = middle + 1;
            } else {
                rightPtr = middle - 1;
            }
        }
        if (rightPtr + 1 >= 0 && rightPtr + 1 < employees.size()) {
            return employees[rightPtr + 1];
        } else {
            return nullptr;
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        if (0 == employees.size()) {
            return 0;
        }

        sort(employees.begin(), employees.end(), [](const Employee* $1, const Employee* $2)->bool{
            return $1->id < $2->id;
        });
        Employee* first = find(employees, id);
        if (nullptr == first) {
            return 0;
        }

        int answer = 0;
        deque<Employee*> queue;
        queue.push_back(first);
        while (!queue.empty()) {
            Employee* item = queue.front();
            queue.pop_front();

            answer += item->importance;
            for (int nextId : item->subordinates) {
                queue.push_back(find(employees, nextId));
            }
        }

        return answer;
    }
};