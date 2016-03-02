all:
	cgogen -out .. vulkan.yml

clean:
	rm -f doc.go types.go const.go cgo_helpers.go cgo_helpers.h
	rm -f vulkan.go

test:
	go build
