/*
    w3util++
    WWW Utility for C++.
    (C) 2017 SiLeader.
    License : MPL2.0
*/

#ifndef SILEADER_WWWUTILPP_WWWUTILPP_HPP
#define SILEADER_WWWUTILPP_WWWUTILPP_HPP

#include <string>
#include <sstream>
#include <algorithm>

#include <boost/lexical_cast.hpp>

namespace w3utilpp {
    namespace detail {
        void replace(std::string& dest, std::string old_str, std::string new_str) {
            std::string::size_type pos=dest.find(old_str);

            while(pos!=std::string::npos){
                dest.replace(pos, old_str.length(), new_str);
                pos=dest.find(old_str, pos+new_str.length());
            }
        }
    } /* detail */
    template<class Arg> std::string uri_creator(const std::string& uri, Arg param) {
        auto colon=uri.find_first_of(":");
        if(colon==std::string::npos)return uri;

        auto slash=uri.find_first_of("/", colon);
        std::string nuri=uri;
        detail::replace(nuri, std::string(nuri.begin()+colon, nuri.begin()+slash), boost::lexical_cast<std::string>(param));

        return nuri;
    }
    template<class Arg, class... Args> std::string uri_creator(const std::string& uri, Arg param, Args... params) {
        auto colon=uri.find_first_of(":");
        if(colon==std::string::npos)return uri;

        auto slash=uri.find_first_of("/", colon);
        std::string nuri=uri;
        detail::replace(nuri, std::string(nuri.begin()+colon, nuri.begin()+slash), boost::lexical_cast<std::string>(param));

        return uri_creator(nuri, params...);
    }

    std::string json_encode(std::initializer_list<std::pair<std::string, std::string>> json) {
        std::stringstream ss;
        ss<<"{";
        for(auto&& elem : json) {
            ss<<"\""<<elem.first<<"\":\""<<elem.second<<"\",";
        }
        std::string s=ss.str();
        s.pop_back();
        s+="}";
        return s;
    }
} /* w3utilpp */

#endif /* end of include guard: SILEADER_WWWUTILPP_WWWUTILPP_HPP */
