#### PHP_SLICE_EXTENSION
Simple implementation of custom php function

-----

To run the function from php you have to execute next command using terminal:

> **Generate necessary files for futher steps**
```
$ phpize
```

The output should be like that:
```
Configuring for:
PHP Api Version:         20131106
Zend Module Api No:      20131226
Zend Extension Api No:   220131226
```
-----

> **Generate makefile**
```
$ ./configure
```

> **Compile**
```
$ make
```

> **Install .so into the directory with PHP extensions**
```
$ make install
```
-----

After previous steps you will be able to add the extension into `php.ini`
```
;;;;;;;;;;;;;;;;;;;;;;
; Dynamic Extensions ;
;;;;;;;;;;;;;;;;;;;;;;

; If you wish to have an extension loaded automatically, use the following
; syntax:
;
;   extension=modulename.extension
;
; For example, on Windows:
;
;   extension=msql.dll
;
; ... or under UNIX:
;
;   extension=msql.so

    extension=slice.so
;
; ... or with a path:
;
;   extension=/path/to/extension/msql.so
```

As a final step, run:
```php 
print_r( slice('Hello, World', from_index[, to_index]) );
```
Or using terminal:
```
php -r "print_r( slice('Hello, World', from_index[, to_index]) );"
```

Also you can run `$ ./build_ext.sh`, to do all the previous steps automatically

=====
Usefull links: 

[Parameter Handling](http://docstore.mik.ua/orelly/webprog/php/ch14_07.htm) &
[Returning Values](http://docstore.mik.ua/orelly/webprog/php/ch14_08.htm)
