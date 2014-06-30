#ifndef BOOSTHELPER_H
#define BOOSTHELPER_H
#include <string>
#include <functional>
#include <algorithm>

namespace boosthelper{
    template< typename CharT >
    inline void TrimLeft(std::basic_string<CharT> &str) {
        str.erase(0, str.find_first_not_of(' '));
    }

    template< typename CharT >
    inline void TrimRight(std::basic_string<CharT> &str) {
        str.erase(str.find_last_not_of(' ') + 1);
    }

    template< typename CharT >
    inline void Trim(std::basic_string<CharT> &str) {
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
    }

    template< typename CharT >
    inline std::basic_string<CharT> TrimCopy(const std::basic_string<CharT> &str) {
        std::basic_string<CharT> str_ = str;
        str_.erase(0, str.find_first_not_of(' '));
        str_.erase(str.find_last_not_of(' ') + 1);
        return str_;
    }

    template<typename CharT>
    inline void Erase(std::basic_string<CharT> &str, const CharT &charactor) {
        str.erase(remove_if(str.begin(), str.end(), 
            bind2nd(std::equal_to<CharT>(), charactor)), str.end());
    }

    template<typename CharT>
    inline void Replace(std::basic_string<CharT> &str, const std::basic_string<CharT> &strObj, const std::basic_string<CharT> &strDest) {
        while(true) {
            CharT pos = str.find(strObj);

            if( pos != std::basic_string<CharT>::npos )
                str.replace(pos, strObj.size(), strDest);
            else
                break;
        }
    }

    template<typename CharT>
    inline std::vector<std::basic_string<CharT> >& Split(std::vector<std::basic_string<CharT> > &seq, const std::basic_string<CharT> &str, CharT separator) {
        if( str.empty() )
            return seq;

        std::basic_stringstream<CharT> iss(str);
        for(std::basic_string<CharT> s; std::getline(iss, s, separator); ) {
            seq.push_back(s);
        }

        return seq;
    }

}

#endif