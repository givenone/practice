#include <iostream>
#include <string>
#include <regex>

using namespace std;

class su{
    public:
    int num[5000];
    int size;
    char sign;
};

void evaluate(string &input, string &operand1, string &operand2, char &op);
void assign(string &operand, su data);
void add(su data1, su data2, su res);
void sub(su data1, su data2, su res);
void mul(su data1, su data2, su res);
void toString(su data, string result);
bool compare(su data1, su data2);


int main()
{
    string input;
    cin >> input;

    string operand1, operand2;
    string result = "";
    char op;
    
    evaluate(input, operand1, operand2, op);

    su data1 = su(), data2 = su(), res;
    cout << 2;
    assign(operand1, data1);
    assign(operand2, data2);
    cout << 3;
    switch(op){
        case '+' :
        if (data1.sign == '-' && data2.sign == '-'){
            add(data1, data2, res);
            res.sign = '-';
            toString(res, result);
            cout << result << endl;
        }
        else if (data1.sign == '-'){
            if (compare(data1, data2) == 1){
                sub(data1, data2, res);
                res.sign = '-';
                toString(res, result);
                cout << result << endl;
            }
            else {
                sub(data2, data1, res);
                toString(res, result);
                cout << result << endl;
            }
        }
        else if (data2.sign == '-'){
            if (compare(data1, data2) == 1){
                sub(data1, data2, res);
                toString(res, result);
                cout << result << endl;
            }
            else {
                sub(data2, data1, res);
                res.sign = '-';
                toString(res, result);
                cout << result << endl;
            }
        }
        else {
            add(data1, data2, res);
            toString(res, result);
            cout << result << endl;
        }
        
        case '-' :
        if (data1.sign == '-' && data2.sign == '-'){
            if (compare(data1, data2) == 1){
                sub(data1, data2, res);
                res.sign = '-';
                toString(res, result);
                cout << result << endl;
            }
            else {
                sub(data2, data1, res);
                toString(res, result);
                cout << result << endl;
            }
        }
        else if (data1.sign == '-'){
            add(data1, data2, res);
            res.sign = '-';
            toString(res, result);
            cout << result << endl;
        }
        else if (data2.sign == '-'){
            add(data1, data2, res);
            toString(res, result);
            cout << result << endl;
        }
        else {
            if (compare(data1, data2) == 1){
                sub(data1, data2, res);
                toString(res, result);
                cout << result << endl;
            }
            else {
                sub(data2, data1, res);
                res.sign = '-';
                toString(res, result);
                cout << result << endl;
            }
        }

        case '*' :
        if (data1.sign == data2.sign){
            mul(data1, data2, res);
            toString(res, result);
            cout << result << endl;
        }
        else {
            mul(data1, data2, res);
            res.sign = '-';
            toString(res, result);
            cout << result << endl;
        }

    } 



}

void evaluate(string &input, string &operand1, string &operand2, char &op){
    cout << 2;

    regex pattern("(-?\\d*)(\\D)(-?\\d*)"); 
    sregex_iterator it(input.begin(), input.end(), pattern);
    smatch m = *it;
    operand1 = m.str(1).c_str();
    operand2 = m.str(3).c_str();
    op = m.str(2).c_str()[0];
}

void assign(string &operand, su data){
    if (operand.at(0) == '-'){
        data.sign = '-';
        for (int i = 1; i < operand.size(); i++)
        {
            data.num[i] = operand.at(operand.size()-i-1) - '0';
        }
    } else {
        for (int i = 0; i < operand.size(); i++)
        {
            data.num[i] = operand.at(operand.size()-i-1) - '0';
        }
    }
    data.size = operand.size();
}

void add(su data1, su data2, su res){
    for (int i = 0; i < max(data1.size, data2.size)+1; i++)
    {
        res.num[i] += data1.num[i] + data2.num[i];
        res.num[i+1] = res.num[i]/10;
        res.num[i] = res.num[i]%10;
    }
    int i;
    for (i = max(data1.size, data2.size)+1; i >0 ; i--)
    {
        if (res.num[i] != 0) break;
    }
    res.size = max(data1.size, data2.size) + 1 - i;
}

void sub(su data1, su data2, su res){
    for (int i = 0; i < max(data1.size, data2.size); i++)
    {
        res.num[i] += data1.num[i] - data2.num[i];
        if (res.num[i] < 0){
            res.num[i] += 10;
            res.num[i+1]--;
        }
    }
    int i;
    for (i = max(data1.size, data2.size); i >0 ; i--)
    {
        if (res.num[i] != 0) break;
    }
    res.size = max(data1.size, data2.size) - i;
}

void mul(su data1, su data2, su res){
    for (int i = 0; i < data1.size; i++)
    {
        for (int j = 0; j < data2.size; j++)
        {
            res.num[i+j] = data1.num[i] * data2.num[j];
            if (res.num[i+j] > 9){
                res.num[i+j+1]++;
            }
        }
        
    }
    int i;
    for (i = max(data1.size, data2.size); i >0 ; i--)
    {
        if (res.num[i] != 0) break;
    }
    res.size = max(data1.size, data2.size) - i;
}

void toString(su data, string result){
    if (data.sign == '-') result = '-';
    for (int i = data.size; i >0; i++)
    {
        result += to_string(data.num[i]);
    }
}

bool compare(su data1, su data2){
    if (data1.size > data2.size) return 1;
    else if (data1.size < data2.size) return 0;
    else{
        for (int i = max(data1.size, data2.size); i > 0 ; i--)
        {
            if (data1.num[i] > data2.num[i]) return 1;
            else if (data1.num[i] < data2.num[i]) return 0;
        }
    }
}