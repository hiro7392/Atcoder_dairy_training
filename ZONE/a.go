package main

import (
	"fmt"
)






func main(){
	var s string
	fmt.Scan(&s)

    text :="ZONe"
	ans:=0
	cnt:=0
	for i:=0;i<12;i++ {
		switch{
		case s[i]==text[cnt]:
			cnt++
		
		case s[i]==text[0]:
			cnt=1
		default:
			cnt=0
		}
		
		if cnt==4{
			ans++
			cnt=0
		}
	}
	fmt.Printf("%d\n",ans)
}