#include "serialize.hpp"

void serialize(std::wofstream& file,vector <wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples) {

   locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
   file.imbue(loc);
    int s=allWords.size();
    for (int i=0;i<s;i++)
    {
        file<<allWords[i]<<L'#';
        int ss=allDefinitions[i].size();
        if (allDefinitions[i].empty()) file<<"";
        else
        {
            for (int j=0;j<ss;j++)
        {

            file<<allDefinitions[i][j]<<L'|';
           file<<L"";

        }
        }

        file<<L'@';
        int sss=allExamples[i].size();
        if (allExamples[i].empty()) file<<"";
        else {
           for (int j=0;j<sss;j++)
        {
            file<<allExamples[i][j]<<L'|';
        }
        }

        file<<endl;
    }

}

void saveTrie(const std::string& filename,vector <wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples) {
    std::wofstream file;
    file.open(filename);
    serialize(file,allWords,allDefinitions,allExamples);
    file.close();
}


void loadTrie(const std::string& filename,vector<wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples) {
    std::wifstream file(filename);
      locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
   file.imbue(loc);
    wstring line;
    while (getline(file,line)) {

       int s=line.size();
       wstring word;
       vector <wstring> definitions;
       vector <wstring> examples;

       int i;
         for (i = 0; i < s; i++) {
            if (line[i] == L'#') {
                word = line.substr(0, i);
                break;
            }
        }

        // Extract the definitions
        if (i < s - 1) {  // Ensuring there is at least one character left after '#'
            wstring defAndExPart = line.substr(i + 1);
            size_t defDelimPos = defAndExPart.find(L'|');
            size_t exDelimPos = defAndExPart.find(L'@');

            while (defDelimPos != wstring::npos) {
                if (defAndExPart[0]==L'@') break;
                wstring definition = defAndExPart.substr(0, defDelimPos);
                definitions.push_back(definition);
                defAndExPart = defAndExPart.substr(defDelimPos + 1);
                defDelimPos = defAndExPart.find(L'|');
            }

          while (exDelimPos != wstring::npos) {
                exDelimPos = defAndExPart.find(L'|');
    wstring example = defAndExPart.substr(0, exDelimPos);
    if (!example.empty()) {
        if (example==L"@") example.clear();
        if (example[0] == L'@') {
            example = example.substr(1);  // Remove the "@" symbol
        }
        if (example[0]==L'|') example.clear();
    }
    if (!example.empty())
    examples.push_back(example);

    if (exDelimPos + 1 < defAndExPart.size()) {
        defAndExPart = defAndExPart.substr(exDelimPos + 1);
    } else {
        defAndExPart.clear();  // Clear the string to exit the loop
    }


}
        allDefinitions.push_back(definitions);
        allExamples.push_back(examples);
        allWords.push_back(word);
    }



}
file.close();
}

