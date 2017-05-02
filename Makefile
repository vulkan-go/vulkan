all:
	c-for-go -ccdefs -out .. vulkan.yml

clean:
	rm -f doc.go types.go const.go
	rm -f cgo_helpers.go cgo_helpers.c cgo_helpers.h
	rm -f vulkan.go

test:
	go build
