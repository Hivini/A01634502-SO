compile:
	gcc hello.c -o hello
	./hello

push:
	git add .
	git commit -m "message"
	git push origin master

clean:
	rm hello