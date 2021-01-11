#include"TextQuery.hpp"

using namespace std;

TextQuery::TextQuery(ifstream& is)
{
    file = make_shared<vector<string>>();
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size()-1; // 当前行号
        istringstream line(text);
        string word;
        while(line >> word){
            // 如果单词不在wm中，以之为下标在wm中添加一项
            auto &lines = wm[word]; // lines是一个shared_ptr
            
            if(!lines) // 第一次遇到该指针时下标为空
            {
                lines.reset(new set<line_no> ); // 分配一个新得set
            }
            lines->insert(n); // 将行号插入
        }
    }
}

QueryResult TextQuery::query(const string& sought) const {
    // 如果未找到sought，我们将返回一个指向此set的指针；
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // 使用find而不是下标运算符，避免将单词加入wm中
    auto loc = wm.find(sought);
    if(loc==wm.end()){
        return QueryResult(sought, nodata, file);
    }
    else{
        return QueryResult(sought, loc->second, file);
    }
    
}

