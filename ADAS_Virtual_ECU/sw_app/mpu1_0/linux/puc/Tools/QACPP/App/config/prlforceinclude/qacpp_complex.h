// qacpp_complex.h
//

#ifndef INCLUDED_QACPP_COMPLEX
#define INCLUDED_QACPP_COMPLEX

//
// Firstly disable any C99 extensions
#ifdef _GLIBCXX_USE_C99_COMPLEX
#  undef _GLIBCXX_USE_C99_COMPLEX
#endif

#define _GLIBCXX_USE_C99_COMPLEX 0


//
// Within system headers, other than where it is guarded by
// _GLIBCXX_USE_C99_COMPLEX, the __complex__ keyword only appears as
// part of a typedef, therefore we can strip the typedef to the end of
// the line.

template <int I> class __qacpp_complex__
{
public:
  template <typename RHS> __qacpp_complex__ & operator=(RHS const &);
  template <typename RHS> __qacpp_complex__ & operator-=(RHS const &);
  template <typename RHS> __qacpp_complex__ & operator+=(RHS const &);
  template <typename RHS> __qacpp_complex__ & operator*=(RHS const &);
  template <typename RHS> __qacpp_complex__ & operator/=(RHS const &);
  template <typename T> operator T & ();
  template <typename T> operator T const & () const;
};

#define __qacpp_complex_ignore__ _ignore_semi
#define __complex__ __qacpp_complex__<__LINE__> _ComplexT ; __qacpp_complex_ignore__

#endif
