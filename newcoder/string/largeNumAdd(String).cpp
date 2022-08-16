class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        if(s.empty())
            return t;
        if(t.empty())
            return s;
        if(s.length()<t.length())
            swap(s, t);
        int carry=0;
        for(int i=s.length()-1;i>=0;i--){
            int temp=s[i]-'0'+carry;
            int j = i - s.length() + t.length();
            if(j>=0)
                temp += t[j] - '0';
            carry = temp / 10;
            temp = temp % 10;
            s[i] = temp + '0';
        }
        if(carry==1)
            s = '1' + s;
        return s;
    }
};