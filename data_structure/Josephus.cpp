/*
 * 学会使用stl的list：
 * （1）erase：会导致指向的迭代器失效。
 * （2）push_back：插入元素
 * （3）begin(),end(),cbegin(),cend()
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    list<int> ring;
    for (int i = 0; i < n; i++) {

        ring.push_back(i+1);
    } 

    list<int>::iterator it = ring.begin();  

    while (ring.size() > 1) {
        for (int j = 1; j < m; j++) {
            // 特殊判断是否是ring的末尾
            it++;
            if (it == ring.end()) {
                it = ring.begin();
            }
        }

        cout << *it << " ";

        // 遍历到位置，考虑如何删除。  
        list<int>::iterator next;
        // 注意：如果使用it++，那么it已经变换了，这时候删除erase会导致对于修改的东西删除！
        next = ++it;
        if (next == ring.end()) {
            next = ring.begin();
        }

        // 关键点
        ring.erase(--it);
        it = next;
    } 

    cout << *it;

    return 0;
}