//两个指针从头遍历，遇到'.'就跳过。遍历版本号时把它转化为数字。每遍历完一个版本号就比较一次
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串 
     * @param version2 string字符串 
     * @return int整型
     */
    int compare(string version1, string version2) {
        int n1=version1.size();
        int n2=version2.size();
        int i=0,j=0;
        while(i<n1||j<n2)
        {
            long long num1=0;
            while(i<n1&&version1[i]!='.')
            {
                num1=num1*10+(version1[i]-'0');
                i++;
            }
            i++;
            long long num2=0;
            while(j<n2&&version2[j]!='.')
            {
                num2=num2*10+(version2[j]-'0');
                j++;
            }
            j++;
            if(num1>num2)
                return 1;
            if(num1<num2)
                return -1;
        }
        return 0;
    }
};
//法2:把两个字符串分解一个一个小字符串（版本号），再比较
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串 
     * @param version2 string字符串 
     * @return int整型
     */
    int compare(string version1, string version2) {
        vector<string> nums1;
        vector<string> nums2;
        istringstream sin1(version1);
        istringstream sin2(version2);
        string temp;
        while(getline(sin1, temp, '.'))
            nums1.push_back(temp);
        while(getline(sin2, temp, '.'))
            nums2.push_back(temp);
        for(int i=0;i<nums1.size()||i<nums2.size();i++)
        {
            string s1=i<nums1.size()?nums1[i]:"0";
            string s2=i<nums2.size()?nums2[i]:"0";
            long long num1=0;
            for(int j=0;j<s1.length();j++)
                num1=num1*10+(s1[j]-'0');
            long long num2=0;
            for(int j=0;j<s2.length();j++)
                num2=num2*10+(s2[j]-'0');
            if(num1>num2)
                return 1;
            if(num1<num2)
                return -1;
        }
        return 0;
    }
};