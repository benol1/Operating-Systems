; Minimal version for print_int, print_string, print_nl
%macro print_int 0
    extern print_int
    call print_int
%endmacro

%macro print_string 0
    extern print_string
    call print_string
%endmacro

%macro print_nl 0
    extern print_nl
    call print_nl
%endmacro
