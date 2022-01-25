/**
将字符串按照字符bound分割，返回一个vector<string>
*/
vector<string> split_by_char(const string& str, char bound) {
    vector<string> ret;
    string every_word;
    for (auto& ch : str) {
        if (ch == bound) {
            ret.push_back(every_word);
            every_word.clear();
        } else {
            every_word += ch;
        }
    }
    if (!every_word.empty()) {
        ret.push_back(every_word);
    }
    return ret;
}
