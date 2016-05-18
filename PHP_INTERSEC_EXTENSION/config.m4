PHP_ARG_ENABLE(intersec, Enable intersec support)

if test "$PHP_INTERSEC" = "yes"; then
   AC_DEFINE(HAVE_INTERSEC, 1, [You have intersec extension])
   PHP_NEW_EXTENSION(intersec, intersec.c, $ext_shared)
fi