PHP_ARG_ENABLE(slice, Enable slice support)

if test "$PHP_SLICE" = "yes"; then
   AC_DEFINE(HAVE_SCLIE, 1, [You have slice extension])
   PHP_NEW_EXTENSION(slice, slice.c, $ext_shared)
fi