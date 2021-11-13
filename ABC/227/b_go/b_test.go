package main

import "testing"


func testCkeck(t *testing.T){
	var sample1=10
	result:=check(sample1)
	expect:=true
	if result!=expect{
		t.Error("expect =",expect,"result=",result)
	}
	t.Log("testCheck finished")
}