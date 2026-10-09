      /*1.数字判断：在0，9上忘记加上''导致不是字符而无法继续输出正确结果
        2.长度判断：开始时<=10,与题目相悖
        3.范围边界：开始时ch两边是开区间，导致最大值最小值取不到
        
        设计测试：San Zhang Kjszhang123
        预期输出：VALID*/
#include <iostream>
#include <string>

bool contains_between(const std::string& text, char lower, char upper) { //声明一个函数，检查字符串里的字符是否在既定范围内
    for (char ch : text) {                                               //将text里的数据逐个赋值给ch
        if (lower <= ch && ch <= upper) {                                //如果ch在lower和upper之间，返回true(problem:一开始没有大于等于小于等于)
            return true;
        }
    }
    return false;
}

bool check_password(const std::string& first_name,                       //声明一个判断密码是否符合要求的函数，名，姓，密码
                    const std::string& last_name,
                    const std::string& password) {
    bool length_ok = password.size() >= 10;                              //检查密码长度是否符合要求 （problem:一开始是小于等于10，与题目相悖）
    bool upper_ok = contains_between(password, 'A', 'Z');                //大写字母
    bool lower_ok = contains_between(password, 'a', 'z');                //小写字母
    bool digit_ok = contains_between(password, '0', '9');                //problem：一开始的数字没有加‘’,导致数据出错，
    bool name_ok = password.find(first_name) == std::string::npos &&     //检查密码中是否有名和姓
                   password.find(last_name) == std::string::npos;        //声明一个变量checked (problem:此变量无用已经删去)
    return length_ok && upper_ok && lower_ok && digit_ok && name_ok;         //若四个条件都满足，返回true，否则false
}

int main() {
    std::string first_name, last_name, password;                         
    if (!(std::cin >> first_name >> last_name >> password)) {
        std::cerr << "请输入：名 姓 密码\n";
        return 1;
    }
    std::cout << (check_password(first_name, last_name, password)
                      ? "VALID" : "INVALID") << '\n';
    return 0;
}
