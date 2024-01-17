#include<bits/stdc++.h>
using namespace std;

set<char> separator,digit,op,alpha;
set<string> rel_op, keywords;
    
void init(){
    separator.insert(';');
    separator.insert(',');
    separator.insert(')');
    separator.insert('(');
    separator.insert('[');
    separator.insert(']');
    separator.insert('{');
    separator.insert('}');
    separator.insert('_');
    separator.insert('+');
    separator.insert('-');
    separator.insert('*');
    separator.insert('/');
    separator.insert('<');
    separator.insert('>');
    separator.insert(' ');
    separator.insert('=');
    


    digit.insert('0');
    digit.insert('1');
    digit.insert('2');
    digit.insert('3');
    digit.insert('4');
    digit.insert('5');
    digit.insert('6');
    digit.insert('7');
    digit.insert('8');
    digit.insert('9');

    op.insert('+');
    op.insert('-');
    op.insert('*');
    op.insert('/');
    op.insert('=');

    rel_op.insert(">");
    rel_op.insert("<");
    rel_op.insert(">=");
    rel_op.insert("<=");
    rel_op.insert("==");
    rel_op.insert("!=");

    for(int i = 0; i < 26; i++)
    {
        // cout<<char('A'+i)<<"   "<<char('a'+i)<<endl;
        alpha.insert(char('A'+i));
        alpha.insert(char('a'+i));
    }

    keywords.insert("if");
    keywords.insert("else");
    keywords.insert("else if");
    keywords.insert("int");
    keywords.insert("float");
}

bool isDigit(char inp){
    return digit.find(inp) != digit.end();
}

bool isOp(char oper){
    return op.find(oper) != op.end();
}

bool isAlpha(char alp){
    return alpha.find(alp) != alpha.end();
}

bool isRelOp(string op){
    return rel_op.find(op) != rel_op.end();
}

bool isSep(char sep){
    return separator.find(sep) != separator.end();
}

bool isKeyword(string s){
    return keywords.find(s) != keywords.end();
}

bool isInteger(string s){
    if(s.size() == 0)
        return false;
    for(char i : s){
        if(isDigit(i) == false)
            return false;
    }
    return true;
}

bool validIdentifier(string s){

    for(char c:s){
        if(!isAlpha(c) || c != '_' || c != ' '){
            return false;
        }
    }
    return true;
}

void parse(string str)
{
	int left = 0, right = 0;
	int len = str.size();

	while (right <= len && left <= right) {
		if (isSep(str[right]) == false)
			right++;

		if (isSep(str[right]) == true && left == right ) {
			if (isOp(str[right]) == true || isRelOp(str.substr(left,right)))
			cout<<str[right]<< " it is a valid operator"<<endl;
            
			right++;
			left = right;
		} else if (isSep(str[right]) == true && left != right
				|| (right == len && left != right)) {
			string subStr = str.substr(left,right`);
            // cout<<"substring "<<subStr<<endl;

			if (isKeyword(subStr) == true)
				cout<<subStr<<" is a keyword"<<endl;

			else if (isInteger(subStr) == true)
				cout<<subStr<<" is a integer"<<endl;

			else if (validIdentifier(subStr) == true
					&& isSep(str[right - 1]) == false)
				cout<<subStr<< " it is a valid identifier"<<endl;

			else if (validIdentifier(subStr) == false
					&& isSep(str[right - 1]) == false)
				cout<<subStr<< " it is not a valid identifier"<<endl;
			left = right;
		}
	}
	return;
}

int main(void){
    init();
    string input;
    cout<<"Enter a String: ";
    cin>>input;
    cout<<"\n"<<endl;
    parse(input);

    return 0;
}