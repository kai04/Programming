# https://example.com/token=crkjhaah124&csrf=guyturyt6868&name=saurav&surname=shrivastava&age=25
import sys
def process(request_urls):
	url = 'https://example.com/token=crkjhaah124&csrf=guyturyt6868&name=saurav&surname=shrivastava&age=25'
	for url in request_urls:
		request_type = url[0]
		request_url = url[1]
		words = request_url.split("&")
		token = words[0].split("token=")[1]
		csrf_token = None
		if request_type =='POST':
			csrf_token = words[1].split("csrf=")[1]
		params = []
		for i in range(len(words)):
			if 'csrf=' not in words[i] and 'token=' not in words[i]:
				parameters =  words[i].split('=')
				params.append(parameters)
		print("token:",token)
		print("csrf token:",csrf_token)
		print("parameters:",params) 
	

if __name__ == '__main__':
	# url = str(input(sys.argv[1]))

	# print(url)
	request_urls = [['GET', 'https://example.com/token=crkjhaah124&name=swati&surname=kunte&age=25&maritial=yes'],['POST', 'https://example.com/token=crkjhaah124&csrf=guyturyt6868&name=saurav&surname=shrivastava&age=25']]
	process(request_urls)