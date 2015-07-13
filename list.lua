--  Author: A Sun	
--  Subject:	Singly Linked List 


-- create a list object
list = {}		

-- The list class table serves as metatable for list objects.
list.__index = list	 
-- The list class also holds all the methods for list objects
-- The list class also serves as a constructor for list objects

setmetatable(list, { __call = function(_, ...)

  -- {length=0} creats a new table (an empty one in this case)
  -- list table is set as the metatable of the new table
  -- Then the new table is assigned to t
  local t = setmetatable({length = 0}, list)

  -- The variable consisting of only an underscore "_" is commonly 
  -- used as a placeholder when you want to ignore the variable
  for _, v in ipairs{...} do t:push(v) end
  return t
end })
 
-- list:push(t) is called several times. This means that self.last is
-- called many times. But after the list has been instantiated, only 
-- one table is in self.last
function list:push(t)
  -- "self" means the list table/object itself.  
  -- self.last is like a ptr in C that moves around to add/remove nodes 
  if self.last then
    self.last._next = t
    t._prev = self.last
    self.last = t
  else
    -- this is the first node
    self.first = t
    self.last = t
  end
  self.length = self.length + 1
end
  
function list:pop()
  if not self.last then return end
  local ret = self.last
  if ret._prev then
    ret._prev._next = nil
    self.last = ret._prev
    ret._prev = nil
  else
    -- this was the only node
    self.first = nil
    self.last = nil
  end
  self.length = self.length - 1
  return ret
end
 
function list:insert(t, after)
  if after then
    if after._next then
      after._next._prev = t
      t._next = after._next
    else
      self.last = t
    end
    t._prev = after
    after._next = t
    self.length = self.length + 1
  elseif not self.first then
    -- this is the first node
    self.first = t
    self.last = t
  end
end

function list:remove(t)
  if t._next then
    if t._prev then
      t._next._prev = t._prev
      t._prev._next = t._next
    else
      -- this was the first node
      t._next._prev = nil
      self._first = t._next
    end
  elseif t._prev then
    -- this was the last node
    t._prev._next = nil
    self._last = t._prev
  else
    -- this was the only node
    self._first = nil
    self._last = nil
  end
 
  t._next = nil
  t._prev = nil
  self.length = self.length - 1
end
 
local function iterate(self, current)
  if not current then
    current = self.first
  elseif current then
    current = current._next
  end
  return current
end
 
function list:iterate()
  return iterate, self, nil
end


