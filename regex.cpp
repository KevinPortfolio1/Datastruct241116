/*

C++ 支持正则表达式，使用的是 <regex> 头文件中的类和函数。通过正则表达式，你可以轻松地进行模式匹配、替换、分割字符串等操作。C++11 引入了对正则表达式的标准支持，使得字符串处理变得更加灵活和强大。
常用的 C++ 正则表达式 API

    std::regex：用于表示正则表达式。
    std::smatch：用于存储匹配的结果。
    std::regex_match：检查整个字符串是否完全匹配正则表达式。
    std::regex_search：检查字符串中是否有子字符串匹配正则表达式。
    std::regex_replace：替换匹配正则表达式的部分内容。

示例 1: 基本正则匹配

下面是一个简单的示例，演示如何使用 C++ 正则表达式进行模式匹配：

*/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string text = "Hello, my number is 123-456-7890";
    
    // 正则表达式：匹配一个简单的电话号码（形式如 123-456-7890）
    regex phone_pattern(R"(\d{3}-\d{3}-\d{4})");
    
    // 使用 regex_search 查找匹配的子串
    smatch matches; // 用于存储匹配的结果
    if (regex_search(text, matches, phone_pattern)) {
        cout << "Found phone number: " << matches.str() << endl;
    } else {
        cout << "No phone number found" << endl;
    }

    return 0;
}

/*
解释：

    regex phone_pattern(R"(\d{3}-\d{3}-\d{4})"); 这是正则表达式，匹配形如 123-456-7890 的电话号码。\d 表示数字，{3} 表示出现三次，- 是字面字符。

    regex_search：用于查找字符串中第一个匹配的部分。如果找到，matches 将包含匹配的信息。

    matches.str()：返回匹配的字符串。

示例 2: 完全匹配

如果你想检查整个字符串是否完全符合某种模式，可以使用 regex_match：

*/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string email = "example@domain.com";
    
    // 正则表达式：匹配简单的电子邮件地址
    regex email_pattern(R"(^\w+@\w+\.\w{2,3}$)");  // 简单的邮箱格式
    
    if (regex_match(email, email_pattern)) {
        cout << "Valid email address!" << endl;
    } else {
        cout << "Invalid email address!" << endl;
    }

    return 0;
}
/*

解释：

    ^：匹配字符串的开始。
    \w+：匹配一个或多个字母、数字或下划线。
    @：字面量的 @ 符号。
    \w+：匹配一个或多个字母或数字，表示域名。
    \.：字面量的点号。
    \w{2,3}：匹配 2 到 3 个字母，表示顶级域名（如 .com、.org 等）。
    $：匹配字符串的结尾。

示例 3: 使用正则表达式替换字符串

你可以使用 regex_replace 来替换字符串中的模式：

*/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string text = "The price is 100 dollars.";
    
    // 正则表达式：匹配数字
    regex price_pattern(R"(\d+)");
    
    // 使用 regex_replace 替换数字为 "[REDACTED]"
    string result = regex_replace(text, price_pattern, "[REDACTED]");
    
    cout << "Updated text: " << result << endl;

    return 0;
}

/*
解释：

    regex_replace 会找到匹配的部分并替换成指定的字符串 [REDACTED]。

示例 4: 正则表达式分割字符串

你还可以使用正则表达式来分割字符串。例如，按空格分割字符串：

*/

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    string text = "Hello, this is a test string.";
    
    // 正则表达式：匹配空格
    regex word_pattern(R"(\s+)");
    
    // 使用 regex_token_iterator 进行分割
    sregex_token_iterator iter(text.begin(), text.end(), word_pattern, -1);
    sregex_token_iterator end;
    
    vector<string> words(iter, end);
    
    // 输出分割后的单词
    for (const auto& word : words) {
        cout << word << endl;
    }

    return 0;
}

/*

解释：

    sregex_token_iterator 用于按匹配模式分割字符串。
    -1 表示获取不匹配部分（即单词）。
    输出结果将是单词的列表，每个单词占一行。

正则表达式语法概述

C++ 正则表达式的语法与其他语言（如 Python、Perl）类似，常见的匹配规则有：

    \d：匹配任何数字。
    \w：匹配任何字母、数字或下划线。
    \s：匹配任何空白字符（空格、制表符、换行符等）。
    +：表示前一个元素出现一次或多次。
    *：表示前一个元素出现零次或多次。
    {n,m}：表示前一个元素出现的次数在 n 到 m 之间。
    ^：匹配字符串的开始。
    $：匹配字符串的结束。
    |：表示“或”操作。
    ()：用于分组。

注意事项：

    C++ 的正则表达式是区分大小写的。如果要忽略大小写，可以使用 regex_constants::icase 标志：

    regex pattern(R"(abc)", regex_constants::icase);

    C++ 的正则表达式性能可能不如某些专门的正则表达式引擎，但对于大多数常见的应用场景来说是足够的。

通过这些基本的操作，你可以在 C++ 中灵活地进行正则表达式匹配和替换等操作。

*/