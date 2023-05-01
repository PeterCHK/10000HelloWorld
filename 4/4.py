import urllib.parse 
encoded_string = "Hello%0AWorld"
decoded_string = urllib.parse.unquote(encoded_string) 
print(encoded_string)
print(decoded_string) # \this\is\a\backslash
