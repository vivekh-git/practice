#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

void printarr(std::vector<std::string>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << std::endl;
}

bool isOperator(std::string& op) {
  return (op == "*" || op == "/" || op == "+" || op == "-");
}

int getWeight(std::string& s) {
  if (s == "*" || s == "/") return 2;
  else if (s == "+" || s == "-") return 1;
  return -1;
}

bool higherprecedence(std::string& s1, std::string& s2) {
  return (getWeight(s1) >= getWeight(s2));
}

void infix_to_postfix(std::vector<std::string>& arr, std::vector<std::string>& result) {
  std::stack<std::string> st;
  for (int i = 0; i < arr.size(); i++) {
    std::cout<< "DEBUG: arr:" << arr[i] << std::endl;
    if (arr[i] == "(") {
      std::cout << "pushing ( to stack" << std::endl;
      st.push(arr[i]);
    }
    else if (!isOperator(arr[i]) && arr[i] != ")") {
      // not operator and not )
      // operand
      std::cout << "pushing operand into result" << std::endl;
      result.push_back(arr[i]);
    }
    else if (isOperator(arr[i])) {
      std::cout << "DEBUG: operator = " << arr[i] << std::endl;
      while (st.size() > 0 && st.top() != "(" && higherprecedence(st.top(), arr[i])) {
        result.push_back(st.top()); 
        st.pop();
      }
      st.push(arr[i]);
    }
    else if (arr[i] == ")") {
      while (st.size() > 0 && st.top() != "(") {
	result.push_back(st.top());
	st.pop();
      }
      st.pop();
    }
  }
  while (st.size() > 0) {
    result.push_back(st.top());
    st.pop();
  }
  return;
}

int evalPostFix(std::vector<std::string>& arr) {
  std::stack<std::string> st;
  for (std::vector<std::string>::iterator it = arr.begin(); it != arr.end(); it++) {
    if (!isOperator(*it)) {
      // operand
      st.push(*it);
    }
    else if (st.size() >= 2) {
      // operator
      std::string st2 = st.top(); st.pop();
      std::string st1 = st.top(); st.pop();
      int num1 = std::stoi(st1);
      int num2 = std::stoi(st2);
      int res = 0;
      if (*it == "*") {
        res = num1 * num2;
      }
      else if (*it == "/") {
        res = num1 / num2;
      }
      else if (*it == "+") {
        res = num1 + num2;
      }
      else if (*it == "-") {
        res = num1 - num2;
      }
      st.push(std::to_string(res));
    }
    else {
      std::cout << " ERROR insufficient args to operator" << std::endl;
    }
  }
  if (st.size() == 1) return stoi(st.top());
  return -1;
}

int evalPreFix(std::vector<std::string>& arr) {
  std::stack<std::string> st;
  for (int i = arr.size()-1; i >= 0; i--) {
    if (!isOperator(arr[i])) {
      // operand
      st.push(arr[i]);
    }
    else if (st.size() >= 2) {
      // operator 
      std::string st1 = st.top(); st.pop();
      std::string st2 = st.top(); st.pop();
      int num1 = std::stoi(st1);
      int num2 = std::stoi(st2);
      int res = 0;
      if (arr[i] == "*") {
        res = num1 * num2;
      }
      else if (arr[i] == "/") {
        res = num1 / num2;
      }
      else if (arr[i] == "+") {
        res = num1 + num2;
      }
      else if (arr[i] == "-") {
        res = num1 - num2;
      }
      st.push(std::to_string(res));
    }
    else {
      std::cout << " ERROR insufficient args to operator" << std::endl;
    }
  }
  if (st.size() == 1) return stoi(st.top());
  return -1;
}


int main() {
  std::string s1 = "2 3 * 5 4 * + 9 -";
  std::string pre = "- + * 2 3 * 5 4 9";

  std::vector<std::string> strvec1, strvec2;
  boost::split(strvec1, s1, boost::is_any_of(" "));
  boost::split(strvec2, pre, boost::is_any_of(" "));
  int res = evalPostFix(strvec1);
  std::cout << "res = " << res << std::endl;

  int res2 = evalPreFix(strvec2);
  std::cout << "res2 = " << res2 << std::endl;

  std::string infix = "12 * ( 3 + 2 )";
  std::vector<std::string> arr;
  boost::split(arr, infix, boost::is_any_of(" "));
  std::vector<std::string> result;
  infix_to_postfix(arr, result);

  std::string resstr;
  if (result.size() > 0) { resstr = result[0]; std::cout << result[0]; }
  for (int i = 1; i < result.size(); i++) {
    std::cout << " " << result[i];
    resstr += " " + result[i];
  }
  std::cout << std::endl;

  std::cout << "resstr = " << resstr << std::endl;
  int res4 = evalPostFix(result);
  std::cout << "res4 = " << res4 << std::endl;

  return 0;
}
