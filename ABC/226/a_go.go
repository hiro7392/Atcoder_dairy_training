package main

import "fmt"

func main(){
	var x float64

	fmt.Scan(&x)

	var xInt int =int(x)

	x-=float64(xInt)
	if x>=0.5 {
		xInt++
	}
	fmt.Println(xInt)
}