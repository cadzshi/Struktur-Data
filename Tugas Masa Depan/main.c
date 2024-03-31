#include "header.h"

int main()
{
    //deklaraso variabel
    tree T;         //tree
    int i, n;       //iterasi
    char str[201];  //query

    //input user
    scanf("%d", &n);
    data c[n];

    //looping sesuai jumlah masukan
    for (i = 0; i < n; i++)
    {
        scanf("%s", str);       //scan query
        Input(n, str, c, i);    //input data sekaligus pisah perquery
    }
    
    //query kedua
    char str1[201];
    scanf("%s", str1);

    //masukkan ke tree dan buat spasi
    InTree(&T, c, n);
    spasi(T.root, 0);

    //print tree
    printTreePreOrder(T.root, 0, 0);

    return 0;
}

/*
14
kuliah#null#0#4#5
kecerdasan_buatan
rekayasa_perangkat_lunak
sistem_informasi
multimedia
jaringan
junior_software_engineer#kuliah#10000000#3#3
basic_software_architecture
basic_convention_code
basic_framework
junior_ui_designer#kuliah#8000000#2#2
ui_framework
ui_testing
junior_ux_designer#kuliah#8000000#2#2
ux_framework
ux_testing
junior_data_scientist#kuliah#10000000#3#2
basic_data_mining
data_library
junior_data_administrator#kuliah#7000000#2#3
dbms_advanced
sql_advanced
nosqlquery_advanced
junior_game_developer#kuliah#11000000#2#2
game_engine
game_platform
junior_cyber_security#kuliah#10000000#3#2
security_protocol
firewall_architecture
senior_ux_designer#junior_ux_designer#15000000#5#2
ux_validation
ux_testing
junior_ux_manager#junior_ux_designer#15000000#5#1
management_skill
senior_ux_manager#junior_ux_manager#20000000#8#1
leadership_skill
java_developer#junior_software_engineer#13000000#4#2
java_framework
java_enterprise
java_platform
senior_software_engineer#junior_software_engineer#16000000#5#2
framework_architecture
professional_code
junior_software_manager#junior_software_engineer#17000000#6#2
project_management
leadership
junior_software_engineer
ini pake kabel wkkwwkw 1234567890`0}{|:"?><>"}
*/