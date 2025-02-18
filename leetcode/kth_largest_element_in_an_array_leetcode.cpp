/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

*/
#include <iostream>
#include <vector>

// QuickSelect 
// выбираем опорный элемент из текущего массива cur,все большие элементы из этого массива
// записываются в дополнительный массив bigger, меньшие в массив smaller, совпадающие в same.
// Еще есть счетчики справа right_count и слева left_count, куда записывается соответственно 
// количество отсеянных и ненужных в хранение больших и меньших элементов, чем искомый
// Проверяем два условия , что right_count +bigger.size() < k и 
// right_count + bigger.size()+same.size() > k-1   
// Если да, то нашли элемент, если нет, то проверяем дополнительные условия:
// right_count + bigger.size()+same.size() < k, то 
// right_count = bigger.size()+same.size(), cur = smaller
// 
// right_count+bigger.size()>=k, то
// cur = bigger, left_count = smaller.size()+same.size()

int main(){
    std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    std::vector<int> cur = nums, bigger, smaller,same;    
    int target, right_count = 0, left_count=0;

    if(nums.size()==1){std::cout << nums[0] << "\n"; return 0;}

    while(true){
        bigger.clear();
        smaller.clear();
        same.clear();
        target = cur[cur.size()/2];
        for(int el: cur){
            if(el > target) bigger.push_back(el);
            if(el == target) same.push_back(el);
            if(el < target) smaller.push_back(el);
        }
        if(right_count+bigger.size() < k && right_count+bigger.size()+same.size()>=k){
            std::cout << target << "\n";
            return 0;
        }
        if(right_count+bigger.size() >= k){
            cur = bigger;
            left_count += smaller.size()+same.size();
        }
        if(right_count + bigger.size()+same.size() < k){
            cur = smaller;
            right_count += bigger.size() + same.size();
        }

    }
    
    return 0;
}

