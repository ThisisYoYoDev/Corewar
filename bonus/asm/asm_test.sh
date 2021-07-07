#!/usr/bin/env bash
make re -C ../../asm/ > /dev/null
cp ../../asm/asm .

# COLOR VAR
cyanclair='\e[1;36m'
vertclair='\e[1;32m'
rougefonce='\e[0;31m'
violetclair='\e[1;35m'
rose='\e[1;31m'
bleufonce='\e[0;34m'
bleuclair='\e[1;34m'
grisclair='\e[0;37m'
jaune='\e[1;33m'
blanc='\e[1;37m'
neutre='\e[0;39m'
rougefonce='\e[91m'

# executalbe asm
EXIT='0'

testrigor()
{
    ./asm $1 &> saveres
    my_rt=$?
    ./real_asm $1 &> saveres
    real_rt=$?
    if [ $my_rt -eq $real_rt ]
    then
        echo -e "${violetclair}TEST :   ${bleuclair}$1${vertclair}\tPASSED${neutre}"
    else
        echo -e "${violetclair}TEST :   ${bleuclair}$1${rougefonce}\tFAILED${neutre}"
        EXIT=1
    fi
}

test()
{
    ./real_asm "file_test_asm/$1.s" &> saveres
    hexdump -C "$1.cor" &> result_real

    ./asm "file_test_asm/$1.s" &> saveres
    hexdump -C "$1.cor" &> test_diff20.txt

    diff result_real test_diff20.txt &> /dev/null
    if [ "$?" -eq "0" ]
    then
        echo -e "${violetclair}TEST :   ${bleuclair}$1${vertclair}\tPASSED${neutre}"
    else
        echo -e "${violetclair}TEST :   ${bleuclair}$1${rougefonce}\tFAILED${neutre}"
        EXIT=1
    fi
    rm "$1.cor" &> /dev/null
}

echo -e "'TEST de rigor  == -84'"
testrigor "file_test_asm/_.s"
testrigor "file_test_asm/MarineKing.s"
testrigor "file_test_asm/42.s"
testrigor "file_test_asm/barriere.s"
testrigor "file_test_asm/empty.s"
testrigor "file_test_asm/lexer_indirect_number1.s"
testrigor "file_test_asm/lexer_indirect_number4.s"
testrigor "file_test_asm/lexer_indirect_number2.s"
testrigor "file_test_asm/lexer_direct_number1.s"
testrigor "file_test_asm/lexer_unexpected_char.s"
testrigor "file_test_asm/lexer_direct_number3.s"
testrigor "file_test_asm/lexer_indirect_number3.s"
testrigor "file_test_asm/lexer_dot.s"
testrigor "file_test_asm/lexer_direct_number2.s"
testrigor "file_test_asm/lexer_label1.s"
testrigor "file_test_asm/lexer_direct.s"
testrigor "file_test_asm/parser_unexpected_token3.s"
testrigor "file_test_asm/parser_unknow_cmd.s"
testrigor "file_test_asm/parser_name_empty.s"
testrigor "file_test_asm/parser_same_label_dec2.s"
testrigor "file_test_asm/parser_same_label_dec.s"
testrigor "file_test_asm/parser_too_many_label_dec.s"
testrigor "file_test_asm/parser_no_label_dec.s"
testrigor "file_test_asm/parser_unclose_string.s"
testrigor "file_test_asm/parser_no_name.s"
testrigor "file_test_asm/parser_no_param.s"
testrigor "file_test_asm/parser_unclose_string2.s"
testrigor "file_test_asm/parser_more_3_param.s"
testrigor "file_test_asm/parser_bad_number_param.s"
testrigor "file_test_asm/parser_need_param.s"
testrigor "file_test_asm/parser_bad_param.s"
testrigor "file_test_asm/parser_unexpected_token2.s"
testrigor "file_test_asm/parser_two_name.s"
testrigor "file_test_asm/parser_two_comment.s"
testrigor "file_test_asm/parser_unexpected_token.s"
testrigor "file_test_asm/bad_label_mod.s"

echo -e ""

echo -e "'TEST de DIFF'"
test "42"
test "_honeybadger"
test "THUNDER"
test "fluttershy"
test "Varimathras"
test "Kappa"
test "gedeon"
test "darksasuke"
test "littlepuppy"
test "Rainbow_dash"
test "ultimate-surrender"
test "turtle"
test "helltrain"
test "_honeybadger"
test "Misaka_Mikoto"
test "zork"
test "loose"
test "dubo"
test "big_feet"
test "bigzork"
test "mandragore"
test "jinx"
test "doge"
test "skynet"
test "live"
test "justin_bee"
test "salamahenagalabadoun"
test "Machine-gun"
test "terminator"
test "casimir"
test "corelol"
test "youforkmytralala"
test "sam_2"
test "Asombra"
test "Wall"
test "champ"
test "meowluigi"
test "ex"
test "corruption"
test "Octobre_Rouge_V4"
test "ppichier"
test "slider2"
test "cepalle2"
test "maxidef"
test "Car"
test "jumper"
test "lolilolxptdr"


rm *.cor saveres result_real test_diff20.txt asm &> /dev/null

exit $EXIT