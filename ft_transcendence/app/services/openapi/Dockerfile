FROM node:alpine

WORKDIR /app

COPY package.json ./

RUN npm install

COPY . .

CMD ["node", "./openapi_service.js"]