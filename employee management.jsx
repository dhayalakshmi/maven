import React, { useEffect, useState } from "react";
import { api, useAuth } from "./Module1_RegistrationAuth";

// ---------------- Employee Management ----------------
const emptyEmployeeForm = {
  employee_code: "",
  first_name: "",
  last_name: "",
  department: "",
  designation: "",
  base_salary: "",
  date_joined: "",
};

export function EmployeeList() {
  const { user } = useAuth();
  const [employees, setEmployees] = useState([]);
  const [form, setForm] = useState(emptyEmployeeForm);
  const [editingId, setEditingId] = useState(null);
  const [error, setError] = useState("");
  const canManage = user?.role === "admin" || user?.role === "hr";

  const loadEmployees = () => {
    api.get("/employees").then(setEmployees).catch((e) => setError(e.message));
  };

  useEffect(() => {
    loadEmployees();
  }, []);

  const handleChange = (e) => setForm({ ...form, [e.target.name]: e.target.value });

  const resetForm = () => {
    setForm(emptyEmployeeForm);
    setEditingId(null);
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError("");
    try {
      if (editingId) {
        await api.put(/employees/${editingId}, form);
      } else {
        await api.post("/employees", form);
      }
      resetForm();
      loadEmployees();
    } catch (err) {
      setError(err.message);
    }
  };

  const handleEdit = (emp) => {
    setEditingId(emp.id);
    setForm({
      employee_code: emp.employee_code,
      first_name: emp.first_name,
      last_name: emp.last_name,
      department: emp.department,
      designation: emp.designation,
      base_salary: emp.base_salary,
      date_joined: emp.date_joined || "",
    });
  };

  const handleDelete = async (id) => {
    if (!window.confirm("Delete this employee?")) return;
    await api.del(/employees/${id});
    loadEmployees();
  };

  return (
    <div className="page">
      <h2>Employee Management</h2>
      {error && <div className="form-error">{error}</div>}

      {canManage && (
        <form className="inline-form" onSubmit={handleSubmit}>
          <input name="employee_code" placeholder="Code" value={form.employee_code} onChange={handleChange} required />
          <input name="first_name" placeholder="First Name" value={form.first_name} onChange={handleChange} required />
          <input name="last_name" placeholder="Last Name" value={form.last_name} onChange={handleChange} required />
          <input name="department" placeholder="Department" value={form.department} onChange={handleChange} required />
          <input name="designation" placeholder="Designation" value={form.designation} onChange={handleChange} required />
          <input name="base_salary" type="number" placeholder="Base Salary" value={form.base_salary} onChange={handleChange} required />
          <input name="date_joined" type="date" value={form.date_joined} onChange={handleChange} />
          <button type="submit">{editingId ? "Update" : "Add"} Employee</button>
          {editingId && <button type="button" onClick={resetForm}>Cancel</button>}
        </form>
      )}

      <table className="data-table">
        <thead>
          <tr>
            <th>Code</th>
            <th>Name</th>
            <th>Department</th>
            <th>Designation</th>
            <th>Base Salary</th>
            <th>Status</th>
            {canManage && <th>Actions</th>}
          </tr>
        </thead>
        <tbody>
          {employees.map((emp) => (
            <tr key={emp.id}>
              <td>{emp.employee_code}</td>
              <td>{emp.full_name}</td>
              <td>{emp.department}</td>
              <td>{emp.designation}</td>
              <td>{emp.base_salary}</td>
              <td>{emp.is_active ? "Active" : "Inactive"}</td>
              {canManage && (
                <td>
                  <button onClick={() => handleEdit(emp)}>Edit</button>
                  <button onClick={() => handleDelete(emp.id)}>Delete</button>
                </td>
              )}
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

// ---------------- Attendance ----------------
export function Attendance() {
  const { user } = useAuth();
  const [records, setRecords] = useState([]);
  const [month, setMonth] = useState(new Date().toISOString().slice(0, 7));
  const [error, setError] = useState("");
  const [message, setMessage] = useState("");
  const employeeId = user?.employee_id;

  const loadAttendance = () => {
    if (!employeeId) return;
    api
      .get(/attendance/employee/${employeeId}?month=${month})
      .then(setRecords)
      .catch((e) => setError(e.message));
  };

  useEffect(() => {
    loadAttendance();
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [month, employeeId]);

  const handleCheckIn = async () => {
    setMessage("");
    setError("");
    try {
      await api.post("/attendance/check-in", { employee_id: employeeId });
      setMessage("Checked in successfully");
      loadAttendance();
    } catch (err) {
      setError(err.message);
    }
  };

  const handleCheckOut = async () => {
    setMessage("");
    setError("");
    try {
      await api.post("/attendance/check-out", { employee_id: employeeId });
      setMessage("Checked out successfully");
      loadAttendance();
    } catch (err) {
      setError(err.message);
    }
  };

  return (
    <div className="page">
      <h2>Attendance</h2>
      {error && <div className="form-error">{error}</div>}
      {message && <div className="form-success">{message}</div>}

      <div className="action-bar">
        <button onClick={handleCheckIn}>Check In</button>
        <button onClick={handleCheckOut}>Check Out</button>
        <input type="month" value={month} onChange={(e) => setMonth(e.target.value)} />
      </div>

      <table className="data-table">
        <thead>
          <tr>
            <th>Date</th>
            <th>Check In</th>
            <th>Check Out</th>
            <th>Status</th>
          </tr>
        </thead>
        <tbody>
          {records.map((r) => (
            <tr key={r.id}>
              <td>{r.date}</td>
              <td>{r.check_in ? new Date(r.check_in).toLocaleTimeString() : "-"}</td>
              <td>{r.check_out ? new Date(r.check_out).toLocaleTimeString() : "-"}</td>
              <td>{r.status}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

// ---------------- Leave ----------------
export function LeaveRequest() {
  const { user } = useAuth();
  const [leaves, setLeaves] = useState([]);
  const [pending, setPending] = useState([]);
  const [form, setForm] = useState({ leave_type: "casual", start_date: "", end_date: "", reason: "" });
  const [error, setError] = useState("");
  const isApprover = user?.role === "admin" || user?.role === "hr";

  const loadMyLeaves = () => {
    if (!user?.employee_id) return;
    api.get(/leave/employee/${user.employee_id}).then(setLeaves).catch((e) => setError(e.message));
  };

  const loadPending = () => {
    if (!isApprover) return;
    api.get("/leave/pending").then(setPending).catch((e) => setError(e.message));
  };

  useEffect(() => {
    loadMyLeaves();
    loadPending();
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [user]);

  const handleChange = (e) => setForm({ ...form, [e.target.name]: e.target.value });

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError("");
    try {
      await api.post("/leave", { ...form, employee_id: user.employee_id });
      setForm({ leave_type: "casual", start_date: "", end_date: "", reason: "" });
      loadMyLeaves();
    } catch (err) {
      setError(err.message);
    }
  };

  const handleDecision = async (id, status) => {
    await api.put(/leave/${id}/decision, { status });
    loadPending();
  };

  return (
    <div className="page">
      <h2>Leave Management</h2>
      {error && <div className="form-error">{error}</div>}

      <form className="inline-form" onSubmit={handleSubmit}>
        <select name="leave_type" value={form.leave_type} onChange={handleChange}>
          <option value="casual">Casual</option>
          <option value="sick">Sick</option>
          <option value="earned">Earned</option>
          <option value="unpaid">Unpaid</option>
        </select>
        <input type="date" name="start_date" value={form.start_date} onChange={handleChange} required />
        <input type="date" name="end_date" value={form.end_date} onChange={handleChange} required />
        <input name="reason" placeholder="Reason" value={form.reason} onChange={handleChange} />
        <button type="submit">Apply Leave</button>
      </form>

      <h3>My Leave Requests</h3>
      <table className="data-table">
        <thead>
          <tr>
            <th>Type</th><th>From</th><th>To</th><th>Days</th><th>Status</th>
          </tr>
        </thead>
        <tbody>
          {leaves.map((l) => (
            <tr key={l.id}>
              <td>{l.leave_type}</td>
              <td>{l.start_date}</td>
              <td>{l.end_date}</td>
              <td>{l.days_count}</td>
              <td>{l.status}</td>
            </tr>
          ))}
        </tbody>
      </table>

      {isApprover && (
        <>
          <h3>Pending Approvals</h3>
          <table className="data-table">
            <thead>
              <tr>
                <th>Employee ID</th><th>Type</th><th>From</th><th>To</th><th>Actions</th>
              </tr>
            </thead>
            <tbody>
              {pending.map((l) => (
                <tr key={l.id}>
                  <td>{l.employee_id}</td>
                  <td>{l.leave_type}</td>
                  <td>{l.start_date}</td>
                  <td>{l.end_date}</td>
                  <td>
                    <button onClick={() => handleDecision(l.id, "approved")}>Approve</button>
                    <button onClick={() => handleDecision(l.id, "rejected")}>Reject</button>
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </>
      )}
    </div>
  );
}