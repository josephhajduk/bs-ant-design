let from_bool = Js.Boolean.to_js_boolean;

[@bs.deriving jsConverter]
type breakpoint = [
  | [@bs.as "xs"] `Xs
  | [@bs.as "sm"] `Sm
  | [@bs.as "md"] `Md
  | [@bs.as "lg"] `Lg
  | [@bs.as "xl"] `Xxl
  | [@bs.as "xxl"] `Xxl
];