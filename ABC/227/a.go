package main

import "fmt"

func main(){
	var n,k,a int

	fmt.Scan(&n,&k,&a)
	a--
	ans:=(a+k)%n
	if ans==0 {
		ans=n;
	}
	fmt.Println(ans)
}