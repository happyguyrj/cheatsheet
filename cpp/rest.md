Rest
- Representational state transfer
    - data is in different formats (representational state) in different layers

Rest API
- implemented over HTTP Protocal
- composed of
    - URI (endpoint/path)
    - parameters: variable in URI path
        - path parameters
            - helps in point towards specific resource
            - https://example.com/customers/1
        - query parameters
            - queries/filters through a list of resources
            - https://example.com/customers?name=abc
    - request payload
    - response body
        - response codes
            - 2xx: Success
            - 3xx: Redirection and other
            - 4xx: problem on client side
            - 5xx: problem on server side
    - HTTP Headers
        - set of attributes corresponding to metadata of API request
- has different methods
    - GET
    - POST
    - PUT
    - DELETE
    - PATCH


HTTP POST
- create a resource (or to trigger some operation on existing resource, or post some data for existing resource)
    - 201: Resource has been created and id is returned
    - 200: Resource has been created and details of resouces are returned
    - 204: Resource processed successfully with no content returned
    - 400: Bad request (Fault with client or browser)
    - 409: Conflict request
- is not idempotent
- can have path parameters
- should not have query parameters
- prefarably have a payload


GET HTTP
- should have a path parameter
- usually does not have request body
- pagination
    - limit
    - offset
- Responses
    - 404: resource not found
    - 200: fetched successfully
- is idempotent


PUT HTTP/PATCH HTTP
- to upsert
- whole request body is to be sent
- if id is present in DB then update, else insert
- if supports upsert
    - id in body, not in path (avoid 404)
- if supports only update
    - id can be in path
- response
    - 404: wrong id in path
    - 400: wrong payload
- put updates whole resource while patch update partly
- idempotent


DELETE HTTP
- only id is mentioned, null body

Filtering and pagination
- using query param for filtering
- limit
- offset


Headers
- metadata for request and response
- Types
    - Request
        - key:value pair is used by server to give more context about request
    - Response
        - key:value pair is used by server to give more context about response
    - Payload
        -
    - Representation
        - key:value pair is used by server to give more context about representation of data


Asynchronous REST APIs
Method1
    - Response
        - 202: Accepted
        - location header contains endpoint code
        - GET with endpoint code gives progress status
    - Response
        - 303
        - location header contains endpoint where resource is created
Method2
    - Response
        - 200: Accepted
        - location body contains endpoint code, status


API Rate Limiting
- Response
    - 429: too many request
- limiting based on key for public APIs
- plan cascadin failure
