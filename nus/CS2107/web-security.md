## Web Security
HTTP: Stateless
* form: action(url), method
* Cookie: data set by server, `set-cookie` response header, sent back with `cookie` header

### Cookie
* value/expiry + MAC using server key
* Use MAC instead of seq num (security by obscurity)
* Scope: control domains, subdomains, paths, that can use cookie (set by server)
    * Domain scope/ path scope: `Set-Cookie: user=john;path=/admin;domain=ex.com`
* Attributes: 
    * `secure`: only sent over https, 
    * `HTTPOnly`: not accessible by javascript
    * `SameSite`: for cross-site requests (`strict/lax`) lax means sent via top-level navigation
* Same-Origin Policy (SOP): Implemented in web browsers, prevents non-same origin tabs sharing information in javascript
    * Prevents direct access of cookies
    * Prevents reading of responses from triggered request (Request is NOT stopped)
    * Same Origin: Protocol/ Host/ Port, Same Site: Protocol/ Last part of domain name

#### Cross-Site Request Forgery (CSRP)
Autosumbit form with `<script>document.evil.submit()</script>`
* Needs auth cookie present + clicked on evil link
* Solution:
    * Check HTTP referrer header
    * CSRF Tokens: Generate unique token per session, included in HTML form as hidden field
    * `SameSite=strict`

#### XSS Attack
* Reflected: Link sent to user, Persistent: Link stored in server
* Solution: Blacklisting (Hard), Whitelisting, Escape untrusted input, `httpOnly`

#### SQL Injection
