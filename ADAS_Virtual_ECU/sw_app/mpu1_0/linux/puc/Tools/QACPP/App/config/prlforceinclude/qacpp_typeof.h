template<typename __type>
struct __qacpp_remove_reference
{
 typedef __type __result;
};
template<typename __type>
struct __qacpp_remove_reference<__type &>
{
 typedef __type __result;
};
#define typeof(__expr) typename __qacpp_remove_reference<decltype((__expr))>::__result
#define __typeof typeof
#define __typeof__ typeof

