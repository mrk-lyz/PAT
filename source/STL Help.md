
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

## PRIORITY_QUEUE
- 查找
    ```c++
    //升序队列，小顶堆
    priority_queue <int,vector<int>,greater<int> > q;
    //降序队列，大顶堆
    priority_queue <int,vector<int>,less<int> > q;
    ```

## 类型转换
- string to int
    ```c++
    string str = "123";
    // stoi
    int a = stoi(str);
    // stringstream
    istringstream is(str);  //构造输入字符串流，流的内容初始化为“123”的字符串   
    int i;
    is >> i;                //从is流中读入一个int整数存入i中 
    ```
- int to string
    ```c++
    // stoi
    string str = to_string("123");
    // stringstream
    int a = 30;
    stringstream s;
    s << a;
    string str = s.str();
    cout << str << endl;
    ```
