# Effective Modern C++笔记

1.模板型别推导 

(代码: code/1-template_deducing_type]

结果

```
----void func_ref(T &param)----
IN = int                 T = int                  param = int&
IN = int const           T = int const            param = int const&
IN = int const&          T = int const            param = int const&
----void func_const_ref(const T &param)----
IN = int                 T = int                  param = int const&
IN = int const           T = int                  param = int const&
IN = int const&          T = int                  param = int const&
----void func_pointer(T *param)----
IN = int                 T = int                  param = int*
IN = int const*          T = int const            param = int const*
IN = int const* const    T = int const            param = int const*
IN = char const* const   T = char const           param = char const*
IN = char const [7]      T = char const           param = char const*
----void func_universal_ref(T &&param)----
IN = int                 T = int&                 param = int&
IN = int const           T = int const&           param = int const&
IN = int const&          T = int const&           param = int const&
IN = int                 T = int                  param = int&&
----void func(T param)----
IN = int                 T = int                  param = int
IN = int const           T = int                  param = int
IN = int const&          T = int                  param = int
IN = int                 T = int                  param = int
IN = int const*          T = int const*           param = int const*
IN = int const* const    T = int const*           param = int const*
IN = char const* const   T = char const*          param = char const*
IN = char const [7]      T = char const*          param = char const*
array size: 7
```

