#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <sock_funs.h>
#include <sock_base.h>
#include <mac_arp.h>






int main() {
    mac_arp mya;
    my_mac m;
    my_arp a;
    //mya.recv_arp(&m, &a);
    char *fake_mac="\xac\x45\x89\x90\x45\x7a";//194 204

/*
    while(1) {
        while(st != 0xffffffff) {
            mya.form_arp(&a,"10.137.0.1" , inet_ntoa(*(struct in_addr*)&st), 2, fake_mac);
            mya.send_arp(&m, &a);
            printf("ip:%s\n",inet_ntoa(*(struct in_addr*)&st));
            st=htonl(st);
            st++;
            st=htonl(st);
        }
        st = inet_addr(tar);
        //sleep(1);
    }
    */

    uint32_t tepp=mya.local_ipend();
    //printf("%s\n",inet_ntoa(i2addr_in(tepp)));
    //mya.arp_cheat("10.137.194.200", "10.137.194.254");


    vector<uint32_t> pr;

    mya.scan_ip_arp(pr, "10.137.194.1", "10.137.194.254");
    for (vector<uint32_t>::iterator it=pr.begin(); it!=pr.end(); it++)
        cout<<inet_ntoa(*(in_addr*)&(*it))<<endl;
    return 0;
}
