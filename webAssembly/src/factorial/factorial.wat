(module
  (func $factorial (param $n i32) (result i32)
    (local $result i32)
    (local $i i32)

    i32.const 1
    local.set $result

    i32.const 1
    local.set $i

    (loop $continue
      local.get $i
      local.get $n
      i32.gt_u
      if
        local.get $result
        return
      end

      local.get $result
      local.get $i
      i32.mul
      local.set $result

      local.get $i
      i32.const 1
      i32.add
      local.set $i

      br $continue
    )

    local.get $result
  )
  (export "factorial" (func $factorial))
)