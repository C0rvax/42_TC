# Docker Commands

## 🛠 Container Management

### List all Containers
```bash
docker ps -a
```

### Remove a Docker Container
```bash
docker rm CONTAINER_ID
```

## 🖼 Image Management

### Find IMAGE_ID
```bash
docker images
```

### Remove a Docker Image
```bash
docker rmi IMAGE_ID
```

## 📜 Logs and Execution

### View Logs
```bash
docker logs CONTAINER
```

### Exec MySQL/MariaDB in Docker
```bash
docker exec -it <CONTAINER_NAME> mysql -u <USERNAME> -p'<PASSWORD>' -h <HOST>
```

### Exec WordPress MariaDB in Docker
```bash
docker exec -it <CONTAINER_NAME> bash -c "mysql -u <USERNAME> -p'<PASSWORD>' -h <HOST> <DATABASE>"
```

## 🛠 Docker Compose Commands

### Start all services
```bash
docker-compose up -d
```

### Stop all services
```bash
docker-compose down
```

### Restart all services
```bash
docker-compose restart
```

### View running services
```bash
docker-compose ps
```

### View logs for all services
```bash
docker-compose logs -f
```

### View logs for a specific service
```bash
docker-compose logs -f <SERVICE_NAME>
```

## 📜 Service-Specific Commands

### Nginx: Test configuration
```bash
docker exec -it <NGINX_CONTAINER> nginx -t
```

### WordPress: Access WordPress CLI
```bash
docker exec -it <WORDPRESS_CONTAINER> wp --info
```

### List of open files | Listen
```bash
sudo lsof -i -P -n | grep LISTEN
```

### MariaDB: Access MariaDB CLI
```bash
docker exec -it <MARIADB_CONTAINER> mysql -u <USERNAME> -p'<PASSWORD>'
```
### Wordpress: login page
- Open your browser and navigate to `http://<SERVER_IP>/wp-admin`.

### Adminer: Access Adminer via browser
- Open your browser and navigate to `http://<SERVER_IP>:<ADMINER_PORT>`.

### FTP Server: Test FTP connection
```bash
ftp <SERVER_IP>
```

### Redis: Access Redis CLI
```bash
docker exec -it <REDIS_CONTAINER> redis-cli
```

### Redis: Flush all cache
```bash
docker exec -it <REDIS_CONTAINER> redis-cli FLUSHALL
```

# 📌 SQL Commands

## 🗂 1. Basic Commands

### 🔍 Show available databases
```sql
SHOW DATABASES;
```

### 📌 Use a specific database
```sql
USE <DATABASE_NAME>;
```

### 📋 Show tables in a database
```sql
SHOW TABLES;
```

### 🏗 Show the structure of a table
```sql
DESCRIBE <TABLE_NAME>;
```
or
```sql
SHOW COLUMNS FROM <TABLE_NAME>;
```

### 📋 Select all data from a table
```sql
SELECT * FROM <USERS>;
```

### 🎯 Filter x results
```sql
SELECT * FROM <USERS> LIMIT x;
```

