FROM alpine:3.15
RUN apk update && \
	apk add --no-cache \
	nginx
EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]
