## Rest
- Representational state transfer
- is an architectural style for distributed hypermedia systems.
- data is in different formats (representational state) in different layers
- is an application programming interface (API or web API) that conforms to the constraints of REST architectural style
- allows for interaction with RESTful web services
- When a client request is made via a RESTful API, it transfers a representation of the state of the resource to the requester or endpoint


## API
- is a set of definitions and protocols for building and integrating application software
- contract between an information provider and an information user
- helps you communicate what you want to that system so it can understand and fulfill the request
- mediator between the users or clients and the resources


### composed of
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

REST has its guiding principles and constraints. These principles must be satisfied if a service interface needs to be referred to as RESTful.
### Guiding Principles of REST
In order for an API to be considered RESTful, it has to conform to these criteria:
#### Uniform Interface
1. Identification of resources- The interface must uniquely identify each resource involved in the interaction between the client and the server.
2. Manipulation of resources through representations– The resources should have uniform representations in the server response. API consumers should use these representations to modify the resources state in the server.
3. Self-descriptive messages – Each resource representation should carry enough information to describe how to process the message. It should also provide information of the additional actions that the client can perform on the resource.
4. Hypermedia as the engine of application state – The client should have only the initial URI of the application. The client application should dynamically drive all other resources and interactions with the use of hyperlinks.

#### Client-server
- A client-server architecture made up of clients, servers, and resources, with requests managed through HTTP.
- client-server design pattern enforces the separation of concerns, which helps the client and the server components evolve independently

#### Stateless
Statelessness mandates that each request from the client to the server must contain all of the information necessary to understand and complete the request.

#### Cacheable
The cacheable constraint requires that a response should implicitly or explicitly label itself as cacheable or non-cacheable.

#### Layered system
- A layered system that organizes each type of server (those responsible for security, load-balancing, etc.) involved the retrieval of requested information into hierarchies, invisible to the client.
- The layered system style allows an architecture to be composed of hierarchical layers by constraining component behavior. In a layered system, each component cannot see beyond the immediate layer they are interacting with.

#### Code on demand
- REST also allows client functionality to extend by downloading and executing code in the form of applets or scripts.
- The downloaded code simplifies clients by reducing the number of features required to be pre-implemented. Servers can provide part of features delivered to the client in the form of code, and the client only needs to execute the code.
- the ability to send executable code from the server to the client when requested, extending client functionality.


### Resource
- key abstraction of information in REST is a resource
- information that we can name can be a resource
- resource representation
    - state of the resource, at any particular time
    - it consist of
        - data
        - metadata
        - hypermedia links that can help the clients in transition to the next desired state
A REST API consists of an assembly of interlinked resources. This set of resources is known as the REST API’s resource model.

#### Resource Identifiers
REST uses resource identifiers to identify each resource involved in the interactions between the client and the server components.

#### Hypermedia
The data format of a representation is known as a media type.
The media type identifies a specification that defines how a representation is to be processed.

A RESTful API looks like hypertext. Every addressable unit of information carries an address, either explicitly (e.g., link and id attributes) or implicitly (e.g., derived from the media type definition and representation structure).

#### Self-descriptive
- resource representations shall be self-descriptive

### Resource Methods
- are used to perform the desired transition between two states of any resource.

#### POST
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

#### GET
- should have a path parameter
- usually does not have request body
- pagination
    - limit
    - offset
- Responses
    - 404: resource not found
    - 200: fetched successfully
- is idempotent

#### PUT/PATCH
##### PATCH
- patch update partly
- whole request body is to be sent
- if id is present in DB then update, else insert
- if supports upsert
    - id in body, not in path (avoid 404)
- if supports only update
    - id can be in path
- response
    - 404: wrong id in path
    - 400: wrong payload
##### PUT
- updates whole resource
- idempotent

#### DELETE
- only id is mentioned, null body

### Filtering and pagination
- using query param for filtering
- limit
- offset


### Headers
metadata for request and response
#### Types
- Request
    - key:value pair is used by server to give more context about request
- Response
    - key:value pair is used by server to give more context about response
- Payload
    -
- Representation
    - key:value pair is used by server to give more context about representation of data


## Asynchronous REST APIs
### Method1
- Response
    - 202: Accepted
    - location header contains endpoint code
    - GET with endpoint code gives progress status
- Response
    - 303
    - location header contains endpoint where resource is created
### Method2
- Response
    - 200: Accepted
    - location body contains endpoint code, status

## API Rate Limiting
- Response
    - 429: too many request
- limiting based on key for public APIs
- plan cascading failure