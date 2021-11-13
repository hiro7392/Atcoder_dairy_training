package main

import "fmt"

func getSx(i int,k int)int{
	return 4*i*k+3*i+3*k;
}

func check(sx int)bool {
	for i:=1;i<=(sx-3)/7;i++{
		for k:=1;k<=(sx-3)/7;k++{
			if sx==getSx(i,k){
				return true
			}
		}
	}
	return false
}

func main(){
	var n int
	fmt.Scan(&n)
	var ans=n;
	for i:=0;i<n;i++{
		var sx int
		fmt.Scan(&sx)
		if check(sx) {
			ans--
		}
	}
	fmt.Println(ans)
}