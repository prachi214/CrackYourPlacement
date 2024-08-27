class Solution {
public:
    string decodeString(string s) {
       stack<string>st;
       for (auto ch:s)
       {
         // start pop chars from stack
if (ch ==']')
{
string stringtorepeat = "";
while (!st.empty() && st.top() != "[")
{
   string top =  st.top();
   stringtorepeat += top;
   st.pop();
}
// ignore opening bracket
st.pop();
string numerictimes = "";
while (!st.empty() && isdigit(st.top()[0]))
{
   // add int chars
   numerictimes += st.top();
   st.pop();
}
// for bigger nums
reverse(numerictimes.begin(), numerictimes.end());
// convert str to integer
int n = stoi(numerictimes);

//decoding
string currentdecode = "";
// repeat char n times
while (n--)
{
currentdecode += stringtorepeat;

}
st.push(currentdecode);
}
else
{
   // store 1 ch
    string temp(1, ch);
    st.push(temp);
}
}
string ans;
       while (!st.empty())
       {
      ans += st.top();
      st.pop();
       }
      //  reverse ans str
       reverse(ans.begin(),ans.end());
       return ans;
        }
};