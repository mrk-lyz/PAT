
## STRING
- 查找
    ```c++
    // 查找args第一次出现
    s.find(args, pos)
    // 查找args任意字符的第一次出现
    s.find_first_of(args, pos)
    // 返回值若等于string::npos，则表示不存在
    ```
  

## VECTOR
- 查找
    ```c++
    vector<int>::iterator it = find(v.begin(), v.end(), 6);
    if (it != v.end())
        cout << *it << endl;
    else
        cout << "can not find" << endl;
    ```

## SET
- 查找
    ```c++
    vector<int>::iterator it = find(vec.begin(), vec.end(), 6);
    if (it != vec.end())
        cout<< *it <<endl;
    else
        cout<< "can not find" << endl;
    ```
  

## MAP
- 查找
    ```c++
    map<int, string>::iterator iter = mp.find(0);    // 返回一个迭代器
    if(iter != mp.end()){
        cout << iter->second << endl;
    } else {
        cout << "can not found" << endl;
    }
    ```
- 遍历
    ```c++
    for(auto iter = mp.begin(); iter != mp.end(); iter++) {
        cout << iter->first << " : " << iter->second << endl;
    }
    ```
