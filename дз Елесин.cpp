#include <iostream>
#include <vector>
#include <algorithm>

class StaticMap {

private: std::vector<std::pair<int, int>> vec;

public: 
    StaticMap(std::vector<std::pair<int, int>> vec1) {

	    for (int i = 0; i < vec1.size(); i++)
        {
		    vec.push_back(vec1.at(i));
	    }
        std::sort(vec.begin(), vec.end());
    }

    bool FindKey(int key, int n) {

        int m = 0, l = 0, r = n - 1;

        while (l != r)
        {
            m = (l + r) / 2;
            if (vec[m].first < key)
                l = m + 1;
            else
                r = m;
        }

        if (vec[m].first == key)
            return true;

        l = 0; 
        r = n - 1;
        while (l < r - 1)
        {
            m = (l + r) / 2;
            if (vec[m].first <= key)
                l = m;
            else
                r = m - 1;
        }

        if (vec[r].first == key)
            return true;

        else if (vec[l].first == key)
            return true;
     
        return false;
    }

    int Get(int key) {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].first == key) return vec[i].second;
        }
        
    }
            
};

int main()
{
    int n, x;
    std::pair<int, int> add;
    std::vector< std::pair<int, int> > vec;
    std::cout << "Enter amount of pairs: ";
    std::cin >> n;
    std::cout << "Enter pairs: " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> add.first >> add.second;
        vec.push_back(add);
    }
    std::cout << "Enter your key: ";
    std::cin >> x;
    StaticMap staticmap = StaticMap(vec);
    if (staticmap.FindKey(x, n) == true)
        std::cout << staticmap.Get(x) << " - your value";
    else
        std::cout << "No key found!";
}